
#include <string>
#include <assert.h>

typedef std::string string;

class Animalia {
    unsigned int mAge;
    string mName;
  public:
    Animalia(string name = "Unknown", int age = 0):
      mName(name), mAge(age) {}
    int age() {return mAge;}
    void age(int nAge) {mAge = nAge;}
    string name() {return mName;}
    void name(string nName) {mName = nName;}

    virtual string breathe() {
      return name() + " breathed.";
    }
};

enum gender_t {MALE, FEMALE};

class Human : public Animalia {
    gender_t mGender;
  public:
    Human(string nName = "Unknown", int nAge = 0, gender_t nGender = FEMALE):
      mGender(nGender) {
        name(nName);
        age(nAge);
      }

    gender_t gender() {return mGender;}
    void gender(gender_t nGender) {mGender = nGender;}

    string breathe() {
      return name() + " breathed through their nose.";
    }

    string echo(string message) {
      return name() + ": " + message;
    }

    string needBathroom() {
      string mode = gender() ? "toilet" : "urinal";
      return "I need to use the " + mode + ".";
    }
};

void animaliaTest() {
  Animalia unknown;
  assert(unknown.name() == "Unknown");
  assert(unknown.age() == 0);
}

void humanTest() {
  Human clark;
  assert(clark.name() == "Unknown");
  assert(clark.age() == 0);
  assert(clark.gender() == FEMALE);

  {
    string expected = "Unknown: I need to use the toilet.";
    assert(clark.echo(clark.needBathroom()) == expected);
  }

  clark.name("Clark");
  clark.age(18);
  clark.gender(MALE);
  assert(clark.name() == "Clark");
  assert(clark.age() == 18);
  assert(clark.gender() == MALE);

  {
    string expected = "Clark: I need to use the urinal.";
    assert(clark.echo(clark.needBathroom()) == expected);
  }
}

int main() {
  animaliaTest();
  humanTest();
  return 0;
}

