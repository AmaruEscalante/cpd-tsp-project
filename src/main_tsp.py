import requests
from subprocess import PIPE, Popen
import os
from dotenv import load_dotenv

# get the api key from the file .env
load_dotenv()
API_KEY = os.getenv("MAPS_KEY")

cities = ["Lima Centro", "Lince", "Miraflores", "Barranco", "Rimac",
          "Los Olivos", "La Molina", "La Victoria", "Magdalena", "San Borja"]


def console_init():
    """Start of the Travelling Salesman program.

    Salute the user, and ask for number of cities he wants to visit.
    Then show him the following options [Lima Centro, Lince, Miraflores, Barranco, Rimac, Los Olivos, La Molina, La Victoria, Magdalena, San Borja].
    He can't repeat cities.
    """
    print("---- Travelling Salesman -----")
    print("Hello, and welcome to the Travelling Salesman program.")
    print("You can choose the following cities:")
    for index, city in enumerate(cities):
        print(f"{index}. {city}")

    print("Please, enter the number of cities you want to visit:")
    number_of_cities = int(input())
    if number_of_cities > len(cities):
        print("You can't choose more cities than the ones available")
        return console_init()
    else:
        # Create a list with the cities chosen by the user
        cities_chosen = []
        for i in range(number_of_cities):
            city = input("Please, enter the name of the city: ")
            if city in cities_chosen:
                print("You can't choose the same city twice")
                return console_init()
            else:
                cities_chosen.append(city)

        print(f"You will visit {number_of_cities} cities")
        print(f"The cities are the following : {cities_chosen}")
        return cities_chosen


def execmd(cmd):
    """
    This function execute any command in the Operative System

    :param cmd: command to be execute
    :return stdout: stdout response from operative system
    """
    print("Command to execute -> {}".format(cmd))
    try:
        # tmp = os.popen(cmd).read()
        p = Popen(cmd, shell=True, stdout=PIPE, stderr=PIPE)
        stdout, stderr = p.communicate()  # this function return bytes (b'some text')
        # convert to string
        stdout = str(stdout, 'utf-8')
        print("stdout: {}".format(stdout))
        stderr = str(stderr, 'utf-8')
        if stderr:
            print("stderr: {}".format(stderr.split("\n")))
    except Exception as e:
        print("Error to execute command ")
        print("Exception occurred -> {}".format(e))
    return stdout


def generate_distance_matrix(chosen_cities):
    cities_url = [city.replace(" ", "+") for city in chosen_cities]
    # Concatenate 'Lima+District+Peru' to every city
    cities_url = [f"{city}+Lima+District+Peru" for city in cities_url]
    # Return the following structure from cities_url:
    # origenes = f"{origen1}|{origen2}|{origen3}|{origen4}|{origen5}|{origen6}"
    origins = "|".join(cities_url)

    # print(origins)
    # Generate url
    # Get the distance matrix from google maps
    url = f"https://maps.googleapis.com/maps/api/distancematrix/json?units=metric&origins={origins}&destinations={origins}&key={API_KEY}"
    # Make a request to the API
    response = requests.get(url)
    # Print the status code of the response.
    # print(response.status_code)
    # Print the content of the response in json format.
    # print(response.json())
    # Save the response as a json file.
    with open("maps_api_google.json", "w") as f:
        f.write(response.text)


if __name__ == "__main__":
    # Start terminal program
    chosen_cities = console_init()
    # Convert chosen cities list to string
    generate_distance_matrix(chosen_cities)

    # Execute TSP program in cpp
    execmd("./main.out > result.txt")
    # Read the result file
    with open("result.txt", "r") as f:
        result = f.read()
    print(result)
