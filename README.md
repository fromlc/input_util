# input_util

1. int getConsoleInt(const string& promptStr = "Enter a positive integer (Q quits): ");
- fetches one validated int from the console
- prompt is an optional parameter that replaces default prompt
- exits app on 'q' or 'Q' entered

2. bool validateInt(int intInput);
- customize validation

3. void setErrorPrompt(const string& errorStr);
- customize error message displayed before prompt is displayed again
