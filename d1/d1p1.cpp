#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

FILE *stream;
int main() {
  freopen_s(&stream, "input", "r", stdin);
  freopen_s(&stream, "output1", "w", stdout);

  std::vector<int> left_list;
  std::vector<int> right_list;

  int left_int, right_int;

  while (std::cin >> left_int >> right_int) {
    left_list.push_back(left_int);
    right_list.push_back(right_int);
  }

  std::sort(left_list.begin(), left_list.end());
  std::sort(right_list.begin(), right_list.end());

  long long ans = 0;
  for (size_t i = 0; i < left_list.size(); ++i) {
    ans += std::abs(left_list[i] - right_list[i]);
  }

  std::cout << ans << std::endl;

  return 0;
}
