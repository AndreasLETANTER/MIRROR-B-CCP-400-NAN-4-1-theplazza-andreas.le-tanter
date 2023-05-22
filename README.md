
# The Plazza

The purpose of this project is to make you realize a simulation of a pizzeria, which is composed of the reception that accepts new commands, of several kitchens, themselves with several cooks, themselves cooking several pizzas.



## Installation

To install The Plazza, you need to follow these steps:

```bash
  git clone git@github.com:AndreasLETANTER/MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter.git
  cd MIRROR-B-CCP-400-NAN-4-1-theplazza-andreas.le-tanter
  cmake .
  make
```
    
## Usage

To run this project, you need to follow these steps:

```bash
./plazza [multiplier] [nb_cooks] [time]
```
- multiplier : multiplier for the cooking time of the pizzas

- nb_cooks : number of cooks per kitchen

- time : time in milliseconds, used by the kitchen stock to replace ingredients

Also, you can run this to get help:
```bash
./plazza
```
or
```bash
./plazza -h
```
## Example
```bash
./plazza 2 5 2000
```


## Authors

- [@Luchooooo](https://github.com/lbarreteau)
- [@HugoN1](https://github.com/HugoN1)
- [@Andréas LE TANTER](https://github.com/AndreasLETANTER)

