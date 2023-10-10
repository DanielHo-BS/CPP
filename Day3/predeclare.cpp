/* forward declaration */

// Error: 'class' has not been declared
class Fred; 
class Barney {
  Fred x; // error: requires complete type Fred
};
class Fred {
  Barney y;
};

int main() {}