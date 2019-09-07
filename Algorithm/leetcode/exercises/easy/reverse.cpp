#include <iostream>
#include <vector>
using namespace std;
int reverse(int);

int main()
{
    cout << reverse(1534236469);
    return 0;
}

int reverse(int x) {
    try {
        int sign = 1;
        if (x < 0) {
            x = -x;
            sign = -1;
        }
        vector<int> places;
        while (x != 0) {
            places.push_back(x % 10);
            x /= 10;
        }
        if (places.size() > 10)
            return 0;

        for (int i = 0; i < places.size(); ++i) {
            for (int j = i+1; j < places.size(); ++j) {
                places[i] *= 10;
            }
            x += places[i];
        }
        x *= sign;
        return x;
    } catch (runtime_error err) {
        return 0;
    } catch (overflow_error err) {
        return 0;
    } catch (underflow_error err) {
        return 0;
    }
}