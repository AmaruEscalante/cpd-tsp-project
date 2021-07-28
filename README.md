# cpd-tsp-project

Implement the TSP Branch and Bound parallel algorithm. TSP Branch and Bound search each path and checks if it is better than the best path so far, if not the algoritm ends the search for that branch.

1. Develop the TSP BB parallel algorithm.
2. Test the source code.
3. Optimization: Allow the software to be interactive to be able to enter two or more cities and find the optimal way between them.

    - Use Lima district matrix:  Lima Centro, Lince, Mi-raflores, Barranco, Rimac, Los Olivos, La Molina, La Victoria, Magdalena, SanBorja.

# Software

- A python script (main_tsp.py) was developped to allow the user to enter two or more cities, search the real distance with Google Maps API and find the optimal way between them.
- C++ program (main.cpp) was developped to implement the TSP BB parallel algorithm and parse input JSON format data.
- Source code are in src/ folder. 
    - This contains Parser.h and Parser.cpp, which are the main classes to parse the input JSON format data.
    - This contains TSPBB.h and TSPBB.cpp, which are the main classes to implement the TSP BB parallel algorithm.
    - This contains main programs and JSON file.
## To use the user console:

1. To execute the program go to src/
2. Start a virtual environment and install the libraries. Follow the commands below:

```
cd src/

python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt

touch .env
```

## To compile c++ code: obtain the source code main.out

```
cd src/
g++ --std=c++11 -Xpreprocessor -fopenmp  main.cpp Algoritmo/*.cpp -o main.out -lomp
```

# Tests the development TSP BB algorithm (parallel and serial)

To test the algoritm need to use Makefile.

## Usage of Makefile:

To execute the test (depends if you want to test the parallel or serial version): 

```
make allsec
make allpar
```

A logging file will be created in tests/ folder to check the results.