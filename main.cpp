#include "iostream"
#include "string"
#include "algorithm"
#include "vector"

class solution
{
    private:
        std::string cridet_adrss;
    public:
        solution(std::string str) : cridet_adrss(str) {}
        int reduce_to_one(int value);
        std::string remove();
        std::string credit_card_valid();
        int summ_of_odd(std::string ss);
        int summ_of_even(std::string ss);
};

int solution :: reduce_to_one(int value)
{
    int result(0);
    while (value != 0)
    {
        result += value % 10;
        value /= 10;
    }
    return result;
}

std::string solution :: remove()
{
    for(int i = 0; i < cridet_adrss.length(); i++)
    {
        if(cridet_adrss[i] == '-' || cridet_adrss[i] == ' ' || cridet_adrss[i] == '_') 
            cridet_adrss.erase(i, 1);
    }
    return cridet_adrss;
}

std::string solution :: credit_card_valid()
{
    remove();
    int sum = summ_of_odd(cridet_adrss) + summ_of_even(cridet_adrss);
    return (sum % 10 == 0) ? "valide" : "non-valide";
}

int solution :: summ_of_odd(std::string ss)
{
    int result(0);
    for(int i = 0; i < ss.length(); i++)
    {
        if(i % 2 != 0) result += (ss[i] - '0');
    }
    return result;
}

int solution :: summ_of_even(std::string ss)
{
    std::vector<int> vec;
    int result(0);
    for(int i = 0; i < ss.length(); i++)
    {
        if(i % 2 == 0) vec.push_back((ss[i] - '0'));
    }
    for(int j = 0; j < vec.size(); j++) vec[j] *= 2;

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] >= 10)
            vec[i] = reduce_to_one(vec[i]);
    }

    for(int x : vec)
        result += x;

    return result;
}


int main ()
{
    solution obj("3566 0020 2036 0505");
    std::cout << obj.credit_card_valid();
}
