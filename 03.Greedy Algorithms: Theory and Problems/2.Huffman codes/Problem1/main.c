#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZESTR 10010
#define COUNT_LETTER 27

typedef struct{
	int freq;
	char letter;
	char cod[26];	
}letter;

typedef struct node{
	int freq;
	char letter;
	char cod;
	struct node* left;
	struct node* right;
} treenode;

/*Очередь с приоритетом*/
void insert(letter* p, treenode *arr_h[]);                 // вставка нового элемента с letter, обёртка над append
void append(treenode* p, treenode *arr_h[]);               // вставка нового элемента с приоритетом
treenode* extract_min(treenode *arr_h[]);                  // извлечь минимум 
treenode* get_min(treenode *arr_h[]);                      // получить минимум             
void remove_ch(char c, treenode *arr_h[]);                 // удалить
void change_priority_letter(char c, int p, treenode *arr_h[]); // изменить приоритет

treenode* haffman(treenode** tree, int* sum);
void obhod_tree(treenode* root, letter* l);
// Получить строку по символьно и заполниь массив структур letter
int getline(char* s, letter code[], int lim, int* count_letter);

//отладочная печать
void print(treenode** a, int s);
void print_tree(treenode* root);

int size;                   // Размер кучи
int index[COUNT_LETTER];    // Масссив для функций изменния приоритета и удаления по БУКВЕ 
 
int main(){
	char str[SIZESTR];
	letter* array_letter;
	treenode** tree, *root;
	int c_letter, len_str, i, sum=0;

	array_letter = (letter*)calloc(COUNT_LETTER, sizeof(letter));

	len_str=getline(str, array_letter, SIZESTR, &c_letter);

	if(c_letter == 1){
		printf("%d %d\n", 1, strlen(str));
		printf("%c: %d\n", array_letter[str[0]-'a'].letter, 0);
		for(i = 0; str[i]; i++)
			printf("%d", 0);
		return 0;
	}

	tree = (treenode*)malloc(sizeof(treenode*) * c_letter);

	for(i = 0; i < COUNT_LETTER; i++) 
		if(array_letter[i].letter != '\0') 
			insert(array_letter + i, tree);
		
	root = haffman(tree,&sum);

	printf("%d %d\n", c_letter, sum);

	for(i = 0; i < COUNT_LETTER; i++) 
		if(array_letter[i].letter != '\0'){
			obhod_tree(root, array_letter + i);
			printf("%c: %s\n", array_letter[i].letter, array_letter[i].cod);
		}
	
	for(i=0; str[i];i++) 
		printf("%s", array_letter[str[i] - 'a'].cod);	
} 


#define MAXVAL 100 /*максимаьная глубина стека val*/
void push(char f);
char pop(void);
char top(void);
void clear(void);

int sp = 0; /*следующая свободная позиция в стеке*/
char val[MAXVAL]; /*стек операндов*/

void obhod_tree(treenode* root, letter* l){
	if (root == NULL) 	
		return;
   
	if(root->cod =='0' || root->cod == '1')
		push(root->cod);

		if(root->letter == l->letter){
			push('\0');
			strcpy(l->cod, val);
			clear();
			return;
		}		
			obhod_tree(root->left, l);
			obhod_tree(root->right, l);
			
			pop();
} 

treenode* haffman(treenode** tree, int* sum){
	int i;
	treenode *tr, *result;
	while(size>1){
		tr = (treenode*)malloc(sizeof(treenode));
		tr->left = extract_min(tree);
		tr->right = extract_min(tree);
		tr->left->cod = '0';
		tr->right->cod = '1';
		tr->freq = tr->left->freq + tr->right->freq;
		*sum += tr->freq;
		append(tr, tree);
	}
	return extract_min(tree);
}

/*Стек*/
void push(char f){
	if(sp < MAXVAL)
		val[sp++] = f;
}

char pop(void){
	if(sp > 0) 
		return val[--sp];
}

char top(void){
	if(sp > 0)
		return val[sp];
}

void clear(void){
	int i;
	for (i = 0; i < MAXVAL; ++i)
		val[i] = '\0';
	sp = 0;
}
/* */

/*getline - считывает строку в s возращает её длину и количесвто добавленных букв*/
int getline(char* s, letter code[], int lim, int* count_letter){
	int c;
	char* t = s;
	
	*count_letter = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
		*s++ = c;
		
		if(code[c - 'a'].letter == '\0'){
			code[c - 'a'].letter = c;
			++*count_letter;
		}
		code[c - 'a'].freq++;
	}

	*s = '\0';
	return s - t;
}

//////////
void print_tree(treenode* root){
	if(root != NULL){
		printf("node: l= %c f= %d  c=%c\n", root->letter, root->freq, root->cod);
		print_tree(root->left);
		print_tree(root->right);
	}
}

void print(treenode** a, int s){
	for(; s > 0; --s){
		printf("%c %d %c \n",(*a)->letter, (*a)->freq, (*a)->cod );
		a++;
	}
	printf("\n");
}
//////////

//очередь с приоритетом
int parent(int i);                         // возращает id родителя 
int left_child(int i);                     // возращает id левого потомка(сына)
int right_child(int i);                    // возращает id правого потомка(сына)
void sift_up(int i, treenode *arr_h[]);                       // всплытие или просееваем вверх
void sift_down(int i, treenode *arr_[]);                     // утопление или просееваем вниз  
void swap(treenode* a, treenode* b);
void swap_index(int* a, int* b);                 // нужна для удаления по Букве 
void remove_m(int i, treenode* arr_h[]);  
void change_priority(int i, int p, treenode* arr_h[]);

int parent(int i){
	return (i - 1) / 2;
}

int left_child(int i){
	return 2 * i + 1;
}

int right_child(int i){
	return 2 * i + 2;
}

void swap_index(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(treenode* a, treenode *b){
	treenode tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sift_up(int i, treenode *arr_h[]){
	while(i > 0 && arr_h[parent(i)]->freq > arr_h[i]->freq){
		swap_index(&index[arr_h[parent(i)]->letter-'a'], &index[arr_h[i]->letter-'a']);
		swap(arr_h[parent(i)], arr_h[i]);
		i = parent(i);
	}
}

void sift_down(int i, treenode *arr_[]){
	int min_index = i;
	int l, r;

	l = left_child(i);
	if(l < size && arr_[l]->freq < arr_[min_index]->freq)
		min_index = l;

	r = right_child(i);
	if(r < size && arr_[r]->freq < arr_[min_index]->freq)
		min_index = r;

	if(i != min_index){
		swap_index(&index[arr_[i]->letter-'a'], &index[arr_[min_index]->letter-'a']);
		swap(arr_[i], arr_[min_index]);
		sift_down(min_index, arr_);
	}
}

void insert(letter *p, treenode *arr_h[]){
	treenode *node;

	node = (treenode*)malloc(sizeof(treenode));
	
	node->letter=p->letter;
	node->freq=p->freq;
	//node->cod=0;
	node->cod='\0';
	node->left=NULL;
	node->right=NULL;
	append(node, arr_h);
}

void append(treenode* p, treenode* arr_h[]){
	
	if (size >= COUNT_LETTER){
		printf("error");
		return;
	}
	arr_h[size] = p;
	index[p->letter - 'a'] = size;
	size++;
	sift_up(size - 1, arr_h);
}

treenode* extract_min(treenode *arr_h[]){
	treenode *result = arr_h[0];
	
	arr_h[0] = arr_h[size - 1];
	index[arr_h[0]->letter - 'a']=index[arr_h[size - 1]->letter - 'a'];
	index[arr_h[size - 1]->letter - 'a'] = 0;
	size--;
	sift_down(0, arr_h);
	return result;
}

treenode* get_min(treenode *arr_h[]){

	return arr_h[0];
}

void remove_ch(char c, treenode *arr_h[]){
	int in;
	treenode* d = get_min(arr_h);
	in = index[c - 'a'];
	if(arr_h[in]->letter == c){
		remove_m(in, arr_h);
	}	
}

void remove_m(int i, treenode *arr_h[]){
	treenode* d = get_min(arr_h);

	arr_h[i]->freq = d->freq-1;
	sift_up(i,arr_h);
	free(extract_min(arr_h));
}

void change_priority_letter(char c, int p, treenode *arr_h[]){
	int in;
	in = index[c - 'a'];
	if(arr_h[in]->letter==c)
	    change_priority(in, p, arr_h);
}

void change_priority(int i, int p, treenode *arr_h[]){
	int oldp;
	
	oldp = arr_h[i]->freq;
	arr_h[i]->freq = p;
	if(p < oldp)
		

sift_up(i,arr_h);
	else
		sift_down(i, arr_h);
}
