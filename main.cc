#include <drogon/drogon.h>
using namespace drogon;

int main() {
    //Catch SIGINT
    app().setLogPath("C:\\Users\\dell\\your_project_name\\")
         .setLogLevel(trantor::Logger::kWarn)
         .setIntSignalHandler([&] {std::cerr << "Alarm! SIGINT!"; app().quit(); })
         //Set HTTP listener address and port
         .addListener("0.0.0.0",80)
         //Load config file
         .loadConfigFile("C:\\Users\\dell\\your_project_name\\config.json")
         //Run HTTP framework,the method will block in the internal event loop
         .run();
    return 0;
}
