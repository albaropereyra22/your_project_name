#include <drogon/drogon.h>
using namespace drogon;

int main() {
    drogon::HttpAppFramework::instance()
        .registerHandler("/slow",
            [=](const HttpRequestPtr& req,
                std::function<void(const HttpResponsePtr&)>&& callback)
            {
                Json::Value json;
                json["result"] = "ok";
                auto resp = HttpResponse::newHttpJsonResponse(json);
                callback(resp);
            },
            { Get,"TimeFilter" });
    drogon::HttpAppFramework::instance()
        .registerHandler("/list_para",
            [=](const HttpRequestPtr& req,
                std::function<void(const HttpResponsePtr&)>&& callback)
            {
                auto para = req->getParameters();
                HttpViewData data;
                data.insert("title", "ListParameters");
                data.insert("parameters", para);
                auto resp = HttpResponse::newHttpViewResponse("ListParameters.csp", data);
                callback(resp);
            });

      
    //start app
    //Catch SIGINT
    app().setIntSignalHandler([&] {std::cerr << "Alarm! SIGINT!"; app().quit(); })
         //Set HTTP listener address and port
         .addListener("0.0.0.0", 80)
         //Load config file
         .loadConfigFile("C:\\Users\\dell\\your_project_name\\config.json")
         // removed because it prevents debugging 
         // select log path and log level
         //.setLogPath("C:\\Users\\dell\\your_project_name\\")
         //.setLogLevel(trantor::Logger::kWarn)
         //Run HTTP framework,the method will block in the internal event loop
         .run();
    return 0;
}
