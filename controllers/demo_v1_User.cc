#include "demo_v1_User.h"

using namespace demo::v1;

// Add definition of your processing function here
void User::signup(const HttpRequestPtr &req,
                 std::function<void (const HttpResponsePtr &)> &&callback,
                 std::string &&userId,
                 const std::string &password,
                 const std::string& verifiedPassword)
{
    LOG_DEBUG<<"User: "<<userId<<" registration ";
    LOG_DEBUG<<"Password: "<<password<<" registration ";
    LOG_DEBUG << "Verified Password: " << verifiedPassword << " registration";
    //Authentication algorithm, read database, verify, identify, etc...
    //...
    Json::Value ret;
    ret["result"]="ok";
    ret["token"]=drogon::utils::getUuid();
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
void User::login(const HttpRequestPtr &req,
                 std::function<void (const HttpResponsePtr &)> &&callback,
                 std::string &&userId,
                 const std::string &password)
{
    LOG_DEBUG<<"User "<<userId<<" login";
    LOG_DEBUG<<"User "<<password<<" ;)";
    //Authentication algorithm, read database, verify, identify, etc...
    //...
    Json::Value ret;
    ret["result"]="ok";
    ret["token"]=drogon::utils::getUuid();
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
void User::getInfo(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback,
                   std::string userId,
                   const std::string &token) const
{
    LOG_DEBUG << "User " << userId << " get his information";
    LOG_DEBUG << "User " << token << " got the token";

    //Verify the validity of the token, etc.
    //Read the database or cache to get user information
    Json::Value ret;
    ret["result"]="ok";
    ret["user_name"]="Jack";
    ret["user_id"]=userId;
    ret["token"] = token;
    ret["gender"]=1;
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}