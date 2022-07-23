#include <iostream>
#include <vector>

using namespace std;

const int DIGIT_LOWER_BOUND = 0;
const int MSB_LOWER_BOUND = 1;
const int BASE = 10;

void print(vector<int> numbers) 
{
    for(int i = 0; i < numbers.size(); i++) 
        cout << numbers[i] << endl;
}

vector<int> add_two_vector(vector<int> vec1, vector<int> vec2)
{
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

bool is_digit(int n)
{
    if(n <= BASE - 1 && n >= DIGIT_LOWER_BOUND)
        return true;
    return false;
}

vector<int> generate_rest_of_number(int digits_number, int digits_difference, int number)
{
    vector<int> numbers;
    int least_significant_digit = number % BASE;
    int next_decreasing_digit = least_significant_digit - digits_difference;
    int next_increasing_digit = least_significant_digit + digits_difference;

    if(digits_number == 0)
    {
        numbers.push_back(number);
        return numbers;
    }

    if(is_digit(next_decreasing_digit))
    {
        int new_number = number * BASE + next_decreasing_digit;
        numbers = add_two_vector(numbers, generate_rest_of_number(digits_number - 1, digits_difference, new_number));
    }
    if(is_digit(next_increasing_digit))
    {
        int new_number = number * BASE + next_increasing_digit;
        numbers = add_two_vector(numbers, generate_rest_of_number(digits_number - 1, digits_difference, new_number));
    }    

    return numbers;
}



vector<int> generate_numbers(int digits_number, int digits_difference, int starting_number)
{
    vector<int> numbers;

    if(!is_digit(starting_number))
        return numbers;

    numbers = add_two_vector(numbers, generate_rest_of_number(digits_number - 1, digits_difference, starting_number));
    numbers = add_two_vector(numbers, generate_numbers(digits_number, digits_difference, starting_number + 1));
    return numbers;
}

vector<int> remove_repeated_numbers(vector<int> numbers)
{
    vector<int> unique_numbers;
    for(int i = 0; i < numbers.size(); i++)
    {
        if(unique_numbers.size() == 0 || numbers[i] != unique_numbers.back())
            unique_numbers.push_back(numbers[i]);
    }
    return unique_numbers;
}

int main()
{
    int n, k;

    cin >> n >> k;
    vector<int> numbers = generate_numbers(n, k, MSB_LOWER_BOUND); 
    numbers = remove_repeated_numbers(numbers);
    print(numbers);
}
