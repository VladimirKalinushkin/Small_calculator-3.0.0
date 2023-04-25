#include "standart_function_for_cpp.h"

void error(string msg)
{

    cin.clear();
    cin.ignore(32000, '\n');

    cerr << msg;
}

string get_word_from_string()
{

    string word = "";
    char c;

    c = getchar();
    if (isalpha(c))
        cin.putback(c);
    else
        throw "Error in function 'get_word_from_string' in down level\n";

    while (cin)
    {

        c = getchar();
        if (isalpha(c) || c == '_' /*|| isnumber(c)*/)
        {

            word.push_back(c);
        }
        else
        {

            cin.putback(c);
            return word;
        }
    }

    return word;
}
vector<string> SplitIntoWords(const string &text)
{
    vector<string> words;
    string word;
    for (const char &c : text)
    {
        if (c == ' ')
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }
    return words;
}
set<string> MakeSet(const vector<string> &query_words)
{
    set<string> s(query_words.begin(), query_words.end());
    return s;
}

void pb_vector(vector<int> &vec, int n)
{
    for (int i = 0; i <= n; i++)
        vec.push_back(i);
}
void swap_vector(vector<int> &vec)
{

    int length = vec.size();
    int num_cicles = length / 2;
    length--;
    int j = 0;
    int reserve;

    for (int i = 0; i <= num_cicles; i++)
    {

        j = length - i;
        reserve = vec[i];
        vec[i] = vec[j];
        vec[j] = reserve;
    }
}
void print_vector(const vector<string> &vec, int count)
{

    for (int i = 0; i < vec.size(); i++)
    {

        cout << vec[i];
        int j = i + 1;
        if (j != vec.size())
            cout << '\t';
        if ((i + 1) % count == 0)
            cout << '\n';
    }

    cout << '\n';
}
void print_vector(const vector<int> &vec, int count)
{

    for (int i = 0; i < vec.size(); i++)
    {

        cout << vec[i];
        int j = i + 1;
        if (i != vec.size())
            cout << '\t';
        if ((i + 1) % count == 0)
            cout << '\n';
    }

    cout << '\n';
}
void print_vector(const vector<double> &vec, int count)
{

    for (int i = 0; i < vec.size(); i++)
    {

        cout << vec[i];
        int j = i + 1;
        if (i != vec.size())
            cout << '\t';
        if ((i + 1) % count == 0)
            cout << '\n';
    }

    cout << '\n';
}

int max_value(const vector<int> &vec)
{

    int length = 0;

    for (int i = 0; i < vec.size(); i++)
    {

        if (vec[i] > length)
            length = vec[i];
    }

    return length;
}
double max_value(const vector<double> &vec)
{

    double length = 0;

    for (int i = 0; i < vec.size(); i++)
    {

        if (vec[i] > length)
            length = vec[i];
    }

    return length;
}

void swap(int &first_op, int &second_op)
{

    int buffer_op;

    buffer_op = first_op;
    first_op = second_op;
    second_op = buffer_op;
}
void swap(string &first_op, string &second_op)
{

    string buffer_op;

    buffer_op = first_op;
    first_op = second_op;
    second_op = buffer_op;
}
void self_sort_v_hm(vector<string> &some_vector)
{

    int max_cicles = some_vector.size() - 1;

    for (int a = 0; a < max_cicles; a++)
    {
        for (int i = 0; i < max_cicles; i++)
        {
            if (some_vector[i] > some_vector[i + 1])
            {
                swap(some_vector[i], some_vector[i + 1]);
            }
        }
    }
}
void self_sort_v_hm(vector<int> &some_vector)
{

    int max_cicles = some_vector.size() - 1;

    for (int a = 0; a < max_cicles; a++)
    {
        for (int i = 0; i < max_cicles; i++)
        {
            if (some_vector[i] > some_vector[i + 1])
            {
                swap(some_vector[i], some_vector[i + 1]);
            }
        }
    }
}

//
