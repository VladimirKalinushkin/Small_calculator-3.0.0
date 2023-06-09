
class Settings
{

    Modes_calculating _mode_calculating;
    Modes_input _mode_input;
    Modes_output _mode_output;
    Modes_output_with_file _mode_output_file;

    string _name_file_to_input;

    public:

        Settings();

        Modes_calculating get_mode() { return _mode_calculating; }
        Modes_input get_mode_input() { return _mode_input; }
        Modes_output get_mode_output() { return _mode_output; }
        Modes_output_with_file get_mode_output_file() { return _mode_output_file; }

        string get_name_file_to_input() { return _name_file_to_input; }

        void set_all_settings();

        void set_mode_input(Modes_input _mode) { _mode_input = _mode; }
        void set_mode_input(Modes_input _mode, string name) { _mode_input = _mode; _name_file_to_input = name; }

        const char *name_file_to_error_log = "error_log.log";

    private:

        void set_Mode_calculating();
        Modes_calculating get_Mode_calculating();

        void set_Mode_output();
        void set_Mode_output_file();

};
