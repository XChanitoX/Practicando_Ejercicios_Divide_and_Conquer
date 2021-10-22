

int main() {
    std::cout << "Problem 3 - Volatile investment\n";
    std::vector<int> stocks = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
    auto [buy, sell] = problem3(std::move(stocks));
    printf("Buying at day %d\nSelling at day %d\n", buy, sell);
}