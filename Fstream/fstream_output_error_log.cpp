

void open_file_to_log(ofstream &file_to_log_error, const Settings &MainSettings)
{
    if (!file_to_log_error.is_open())
        file_to_log_error.open(MainSettings.name_file_to_error_log, ios::app);
}