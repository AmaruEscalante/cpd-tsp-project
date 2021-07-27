# cpd-tsp-project

To execute the program go to src/
Start a virtual environment and install the libraries

```
cd src/
g++ --std=c++11 main.cpp Algoritmo/*.cpp -o main.out
g++ --std=c++11 -Xpreprocessor -fopenmp  main.cpp Algoritmo/*.cpp -o main.out -lomp

python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt

touch .env
```
