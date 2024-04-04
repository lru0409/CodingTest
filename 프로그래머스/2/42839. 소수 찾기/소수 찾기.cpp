#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

set<int> primes;
bool visited[7];

int ToInt(vector<char>& vec)
{
    int result = 0;
    for(int i = 0; i < vec.size(); i++)
        result = result * 10 + vec[i] - '0';
    return result;
}
    
bool IsPrime(int num)
{
    if (num <= 1)
        return false;
    for(int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

void Recursive(const string& numbers, vector<char>& vec)
{
    if (IsPrime(ToInt(vec)))
        primes.insert(ToInt(vec));
    if (vec.size() == numbers.length())
        return;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        vec.push_back(numbers[i]);
        Recursive(numbers, vec);
        vec.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers)
{
    vector<char> vec;
    Recursive(numbers, vec);
    return primes.size();
}