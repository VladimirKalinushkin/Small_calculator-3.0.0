
class Settings
{

    public:

        Settings();

        void main_menu_to_set_all_settings();

        Modes_calculating get_mode_calculating() { return _mode_calculating; }
        Modes_output get_mode_output() { return _mode_output; }
        Modes_output_with_file get_mode_output_with_file() { return _mode_output_with_file; }

        Modes_input get_mode_input() { return _mode_input; }
        string get_name_file_to_input() { return _name_file_to_input; }

        string get_name_file_to_output() { return _name_file_to_output; }

        void set_mode_input(Modes_input _mode) { _mode_input = _mode; }
        void set_mode_input(Modes_input _mode, string name) { _mode_input = _mode; _name_file_to_input = name; }
        const char *name_file_to_error_log = "error_log.log";

    private:

        Modes_calculating _mode_calculating;
        Modes_output _mode_output;
        Modes_output_with_file _mode_output_with_file;

        Modes_input _mode_input;
        string _name_file_to_input;

        string _name_file_to_output;

        void set_mode_calculating();
        void set_mode_output();
        void set_mode_output_with_file();
        void set_name_file_to_output();

};
