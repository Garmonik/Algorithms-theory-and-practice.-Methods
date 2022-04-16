#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using Segment = std::pair<int, int>;

std::vector<int> get_covering_set(std::vector <Segment> segments){
  std::vector <int> result;

  std::sort(segments.begin(), segments.end(), [=](const Segment& lhs, const Segment& rhs) { return lhs.first < rhs.first; } );
  
  // fix this function
  for(auto it=segments.begin(); it != segments.end(); it){
    
    auto it2 = it+1;
    int minx2 = it->second;
    while(it2 != segments.end() && minx2 >= it2->first){
        minx2 = std::min(minx2, it2->second);
        it2++;  
    }
      
	result.push_back(minx2);
	it = it2;
  }

  return result;
}

int main(void){
  int segments_count;
  std::cin >> segments_count;
  std::vector <Segment> segments(segments_count);
  for(auto &s:segments){
    std::cin >> s.first >> s.second;
  }

  auto points = get_covering_set(std::move(segments));
  
  std::cout << points.size() << std::endl;
  for(auto point:points){
    std::cout << point << " ";
  }
  std::cout << std::endl;
}
