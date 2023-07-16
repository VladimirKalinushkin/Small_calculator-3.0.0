
void error(string msg);
void clear_istream(istream &is);

string get_word_from_string(istream &is);
vector<string> SplitIntoWords(const string &text);
set<string> MakeSet(const vector<string> &query_words);

void pb_vector(vector<int> &vec, int n);
void swap_vector(vector<int> &vec);
void print_vector(const vector<string> &vec, int count);
void print_vector(const vector<int> &vec, int count);
void print_vector(const vector<double> &vec, int count);

int max_value(const vector<int> &vec);
double max_value(const vector<double> &vec);

void swap(int &first_op, int &second_op);
void swap(string &first_op, string &second_op);
void self_sort_v_hm(vector<string> &some_vector);
void self_sort_v_hm(vector<int> &some_vector);

void get_delay_indicator_with_functiion(auto &function, auto &parameter);

void Delay_indicator(int second);
void Delay_indicator(bool &end);

//
