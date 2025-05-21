#include <print>

import indicate;

int main() {
    using namespace indicate;
    Style trace_style = Style().foreground(Color::BrightYellow()).background(Color::Black());
    Style debug_style = Style().foreground(Color::BrightGreen()).background(Color::Blue());
    Style info_style  = Style().foreground(Color::BrightCyan()).background(Color::Black());
    Style warn_style  = Style().foreground(Color::BrightRed()).background(Color::Black());
    Style error_style = Style().foreground(Color::BrightWhite()).background(Color::Red());
    Style fatal_style = Style().foreground(Color::BrightWhite()).background(Color::Magenta());

    std::println("{}", trace_style("Trace: This is a trace message"));
    std::println("{}", debug_style("Debug: This is a debug message"));
    std::println("{}", info_style("Info: This is an info message"));
    std::println("{}", warn_style("Warning: This is a warning message"));
    std::println("{}", error_style("Error: This is an error message"));
    std::println("{}", fatal_style("Fatal: This is a fatal error message"));
    std::println("This is a normal message without any style");
}