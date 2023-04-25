
class Settings
{

    Modes_calculating _mode_calculating;

    public:

        Settings();

        Modes_calculating get_mode() { return _mode_calculating; }

        void set_all_settings();

    private:

        class exeption : public exception
        {
        public:
            exeption(char *msg);

            void what();

        private:
            char *message = NULL;
        };

        void set_Mode_calculating();
        Modes_calculating get_Mode_calculating();

};
