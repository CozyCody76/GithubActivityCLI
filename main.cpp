#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main(){
    std::ifstream infile("events.json");

    if(!infile.is_open()){
        std::cout << "Cannot open events.json file.\n";
        std::cout << "Usage: python fetch.py 'Username' to fetch the events.json.\n";
        return 1;
    }

    json events;
    infile >> events;

    if(events.empty()){
        std::cout << "No recent activity";
        return 0;
    }

    for(int i = 0; i < events.size(); i++){
        const auto& event = events[i];
        std::string type = event.value("type", "UnknownEvent");
        std::string name = event["actor"].value("display_login", "UnknowLogin");
        std::string repo = event["repo"].value("name", "UnkownnRepo");
        std::string ref = event["payload"].value("ref", "UnknownBranch");
        
        if(type == "PushEvent"){
            std::string branch = ref.substr(ref.find_last_of("/") + 1);
            std::cout << name << " push to " << branch << " in " << repo << ".\n";
        }else if(type == "PublicEvent"){
            std::cout << name << " make " << repo << " publish. \n";
        }else if(type == "IssueEvent"){
            int number = event["payload"]["issue"].value("number", 0);
            std::cout << name << " created issue " << number << ".\n";
        }else if(type == "IssueCommentEvent"){
            int number = event["payload"]["issue"].value("number", 0);
            std::cout << name << " commented on issue " << number << ".\n";
        }else if(type == "WatchEvent"){
            std::cout << name << " starred " << repo << ".\n";
        }else if(type == "PullRequestEvent"){
            int number = event["payload"]["pull_request"].value("nubmer", 0);
            std::cout << name << " created pull request " << number << ".\n";
        }else if(type == "CreateEvent"){
            std::string ref_type = event["payload"].value("ref_type", "UnknowRefType");
            std::cout << name << " created " << ref_type << " " << ref << ".\n";
        }else{
            std::cout << "Event type: "<< type << ".\n";
        }
    }

    return 0;
}