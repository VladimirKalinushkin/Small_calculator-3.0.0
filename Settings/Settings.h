
class Settings
{

    Modes_calculating _mode_calculating;
    Modes_input _mode_input;

    string _name_file_to_input;

    public:

        Settings();

        Modes_calculating get_mode() { return _mode_calculating; }
        Modes_input get_mode_input() { return _mode_input; }
        string get_name_file_to_input() { return _name_file_to_input; }

        void set_all_settings();
        void set_mode_input(Modes_input _mode) { _mode_input = _mode; }
        void set_mode_input(Modes_input _mode, string name) { _mode_input = _mode; _name_file_to_input = name; }

    private:

        void set_Mode_calculating();
        Modes_calculating get_Mode_calculating();
        class exeption : public exception
        {
        public:
            exeption(char *msg);

            void what();

        private:
            char *message = NULL;
        };


};
