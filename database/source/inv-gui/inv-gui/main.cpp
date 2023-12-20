#include "MyForm.h"

using namespace invgui;

int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MyForm());
    return 0;
}
