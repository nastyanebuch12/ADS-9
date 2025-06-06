// Copyright 2022 NNTU-CS
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "tree.h"

int factorial(int n) {
  int res = 1;
  for (int i = 2; i <= n; ++i) res *= i;
  return res;
}
void printVector(const std::vector<char>& v) {
  for (char ch : v)
    std::cout << ch;
  std::cout << "\n";
}

int main() {
  std::srand(time(0));
  std::vector<char> set = { '1', '2', '3', '4'};
  PMTree tree(set);
  std::cout << "getAllPerms:" << "\n";
  auto perms = getAllPerms(tree);
  for (const auto& p : perms) printVector(p);
  std::cout << "\n";
  std::cout << "getPerm1 with number 3: ";
  printVector(getPerm1(tree, 3));
  std::cout << "getPerm2 with number 5: ";
  printVector(getPerm2(tree, 5));
  std::cout << "\n";
  std::cout << "n\t" << "getAllPerms(ms) "
       << "getPerm1(ms) " << "getPerm2(ms)" << "\n";
  for (int n = 1; n <= 10; ++n) {
    std::vector<char> set1;
    for (int i = 0; i < n; ++i) set1.push_back('a' + i);
    PMTree tree(set1);
    int total = factorial(n);
    int num = std::rand() % total + 1;
    auto time1_start = std::chrono::high_resolution_clock::now();
    getAllPerms(tree);
    auto time1_end = std::chrono::high_resolution_clock::now();
    double time1 =
    std::chrono::duration<double, std::milli>(time1_end - time1_start).count();

    auto time2_start = std::chrono::high_resolution_clock::now();
    getPerm1(tree, num);
    auto time2_end = std::chrono::high_resolution_clock::now();
    double time2 =
    std::chrono::duration<double, std::milli>(time2_end - time2_start).count();

    auto time3_start = std::chrono::high_resolution_clock::now();
    getPerm2(tree, num);
    auto time3_end = std::chrono::high_resolution_clock::now();
    double time3 =
    std::chrono::duration<double, std::milli>(time3_end - time3_start).count();
    std::cout << n << "\t" << time1 << "\t\t" << time2 << "\t\t" << time3
              << "\n";
  }
  return 0;
}
