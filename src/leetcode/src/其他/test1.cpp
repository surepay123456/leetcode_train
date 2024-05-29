#include <iostream>
#include <memory>
#include <vector>
int main() {
    std::vector<std::shared_ptr<int>> v;
    v.emplace_back(new int(1));
    // 这里的emplace_back是要申请内存的 如果构造共享指针失败 new出的内存就泄露了
    v.emplace_back(std::make_shared<int>(1));
    // 如果用make_shared 申请内存和构造共享指针同时进行。
    std::cout << "ok !" << std::endl;
    return 0;
    // 为什么要用std::make_shared 而不用 new
}