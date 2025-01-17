class Translator
{
 public:

 virtual ~Translator(void)
 {
 }

 virtual const char* operator ()(int number) = 0;
};

class SimpleTranslator : public Translator
{
 public:

 const char* operator ()(int number)
 {
  snprintf(buf, sizeof(buf), "%04X", number);
  return buf;
 }

 private:

 char buf[64];
};

class AggTranslator : public Translator
{
 public:

 virtual const char* operator ()(int number) = 0;
 virtual int operator ()(const char* name) = 0;
};

class SimpleAggTranslator : public AggTranslator
{
 public:

 int operator()(const char* name)
 {
  return names += name;
 }

 const char* operator ()(int number)
 {
  return names[number];
 }

 private:

 Names names;
};
