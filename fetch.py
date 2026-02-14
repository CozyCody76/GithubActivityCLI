import urllib.request
import json 
import sys

if len(sys.argv) < 2:
    print("Usage: python fetch.py <username>")
    sys.exit(1)

username = sys.argv[1]


def fetch(username):
    url = f"https://api.github.com/users/{username}/events"
    request = urllib.request.Request(
        url,
        headers={"User-Agent": "github-activity-cli"}
    )

    try:
        with urllib.request.urlopen(request) as response:
            if response.status == 403:
                print("Polling rate limit exceed.")
                
            if response.status != 200:
                print(f"HTTPS Error: {response.status}")
                return
            data = response.read().decode()
        
        with open("events.json", "w", encoding="utf-8") as f:
            f.write(data)
        
        print("Events saved to events.json file")
    except Exception as e:
        print(e)

fetch(username)
