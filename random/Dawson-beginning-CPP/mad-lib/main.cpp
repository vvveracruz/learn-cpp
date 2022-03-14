#include "main.hpp"

string askText( string prompt ) {

  string text;

  cout << prompt;
  getline( cin, text );

  return text;

}

int askNumber( string prompt ) {

  int number;

  cout << prompt;
  cin >> number;

  return number;

}

void tellStory( string name, string noun, string bodyPart, string verb, int number ) {

  cout << "\nHere's your story:\n\n";
  cout << "The famous explorer " << name << " had nearly given up a life-long quest to find \n";
  cout << "The lost city of " << noun << " when one day, the " << noun << " found the explorer.\n";
  cout << "Surrounded by " << number << " " << noun << ", a tear came to " << name << "'s " << bodyPart << ".\n";
  cout << "After all this time the quest was finally over. " << "And then the " << noun << " promptly devoured " << name << ".\n";
  cout << "The moral of the story? Be careful what you " << verb << " for.";

}

int main() {

  cout << "Welcome to Mad Lib.\n\n";
  cout << "Answer the following questions to help create a new story.\n";

  string name = askText( "Please enter a name: ");
  string noun = askText( "Please enter a plural noun: ");
  string bodyPart = askText( "Please enter a body part: ");
  string verb = askText( "Please enter a present tense verb: ");
  int number = askNumber( "Please enter a number: ");

  tellStory( name, noun, bodyPart, verb, number );

  return 0;

}
