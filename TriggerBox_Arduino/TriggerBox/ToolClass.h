#pragma once

class Tool
{
public:
  virtual void reset()
  {
    Serial.println("Tools reset function");
  }
  virtual void run()
  {
    Serial.println("Tools says hi");
  };

  virtual void run(int i)
  {
    Serial.println("Tools says hi");
  };

  virtual void run(int i, int y)
  {
    Serial.println("Tools says hi");
  };

  virtual void run(int i, int y, int p)
  {
    Serial.println("Tools says hi");
  };
};