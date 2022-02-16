import http.client
import json


def get_group_stage_data():
    connection = http.client.HTTPSConnection("v3.football.api-sports.io")
    headers = {
        'x-rapidapi-host': "v3.football.api-sports.io",
        'x-rapidapi-key': "5ff4c94335eb9dcb17e6dcff063648e8"
        }
    connection.request("GET", "/standings?league=1&season=2018", headers=headers)
    result = connection.getresponse()

    return result.read().decode("utf-8")


def save_group_stage_data_to_json_file():
    data = get_group_stage_data()
    jsonFile = open("../../data/GroupStageData.json", "w")
    jsonFile.write(json.dumps(json.loads(data), indent=4, sort_keys=True))


def main():
    save_group_stage_data_to_json_file()


if __name__ == "__main__":
    main()
