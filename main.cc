#include <drogon/drogon.h>

int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0",80);
    //Load config file
    drogon::app().loadConfigFile("C:\\Users\\dell\\your_project_name\\config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    drogon::app().setIntSignalHandler([&] {std::cerr << "Alarm! SIGINT!"; });
    return 0;
}
