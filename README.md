# Quantum circuit simulator

#### A basic Quantum Circuit Simulator using linked lists

### Quantum Computing

Quantum computing studies computation systems (quantum computers) that make direct use of quantum-mechanical phenomena, such as superposition and entanglement, to perform operations on data. Quantum computers are different from binary digital electronic computers based on transistors. Whereas common digital computing requires that the data be encoded into binary digits (bits), each of which is always in one of two definite states (0 or 1), quantum computation uses quantum bits (qubits).

### Qubits

In quantum computing, a qubit is a unit of quantum information the quantum analogue of the classical bit. However, quantum mechanics allows the qubit to be in a superposition of both states at the same time, a property that is fundamental to quantum computing.

### Input

The quantum circuit simulator takes as input the number of qubits (n) and the gates involved in the circuit.
For n qubits, a matrix of order 2^n x 2^n  is generated which turns out to be an identity matrix of the same order. This is the input matrix which holds the states of the qubits.
Based on the number of qubits, the matrices for the quantum gates are generated;the tensor product of n one-qubit gates gives the unitary matrix for n qubits.

### Output

The output is a matrix of order 2^n x 2^n. Matrix multiplication of the input matrix and all the unitary matrices(that represent the quantum gates) used in the circuit gives the output matrix. The output matrix shows the corresponding qubit state for the respective input states formed in the input matrix. 

## Authors

* **Jugal Wadhwa**
* **Aman Malali** 

