module;

#include <array>
#include <string>
#include <cstdio>

#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

export module indicate.util;


namespace indicate {

    export struct Color {
        enum class Value : int {
            Default = 0,
            Black,
            Red,
            Green,
            Yellow,
            Blue,
            Magenta,
            Cyan,
            White,
            BrightBlack,
            BrightRed,
            BrightGreen,
            BrightYellow,
            BrightBlue,
            BrightMagenta,
            BrightCyan,
            BrightWhite,

            Count  // sentinel
          };

    private:
        Value v_;
        static constexpr size_t N = static_cast<size_t>(Value::Count);

        static constexpr std::array<std::string_view, static_cast<size_t>(Value::Count)> fg_codes = {
            "\x1b[39m",  // Default
            "\x1b[30m",  // Black
            "\x1b[31m",  // Red
            "\x1b[32m",  // Green
            "\x1b[33m",  // Yellow
            "\x1b[34m",  // Blue
            "\x1b[35m",  // Magenta
            "\x1b[36m",  // Cyan
            "\x1b[37m",  // White
            "\x1b[90m",  // Bright Black
            "\x1b[91m",  // Bright Red
            "\x1b[92m",  // Bright Green
            "\x1b[93m",  // Bright Yellow
            "\x1b[94m",  // Bright Blue
            "\x1b[95m",  // Bright Magenta
            "\x1b[96m",  // Bright Cyan
            "\x1b[97m"   // Bright White
          };

        static_assert(fg_codes.size() == N, "fg_codes must match Color::Value count");

        static constexpr std::array<std::string_view, static_cast<size_t>(Value::Count)> bg_codes = {
            "\x1b[49m",  // Default
            "\x1b[40m",  // Black
            "\x1b[41m",  // Red
            "\x1b[42m",  // Green
            "\x1b[43m",  // Yellow
            "\x1b[44m",  // Blue
            "\x1b[45m",  // Magenta
            "\x1b[46m",  // Cyan
            "\x1b[47m",  // White
            "\x1b[100m", // Bright Black
            "\x1b[101m", // Bright Red
            "\x1b[102m", // Bright Green
            "\x1b[103m", // Bright Yellow
            "\x1b[104m", // Bright Blue
            "\x1b[105m", // Bright Magenta
            "\x1b[106m", // Bright Cyan
            "\x1b[107m"  // Bright White
        };

        static_assert(bg_codes.size() == N, "bg_codes must match Color::Value count");

    public:
        constexpr explicit Color(const Value c) : v_(c) {}

        [[nodiscard]] constexpr std::string_view to_ansi_fg() const noexcept {
            return fg_codes[static_cast<size_t>(v_)];
        }

        [[nodiscard]] constexpr std::string_view to_ansi_bg() const noexcept {
            return bg_codes[static_cast<size_t>(v_)];
        }

        static constexpr Color Default()     noexcept { return Color(Value::Default); };
        static constexpr Color Black()       noexcept { return Color(Value::Black);   };
        static constexpr Color Red()         noexcept { return Color(Value::Red);     };
        static constexpr Color Green()       noexcept { return Color(Value::Green);   };
        static constexpr Color Yellow()      noexcept { return Color(Value::Yellow);  };
        static constexpr Color Blue()        noexcept { return Color(Value::Blue);    };
        static constexpr Color Magenta()     noexcept { return Color(Value::Magenta); };
        static constexpr Color Cyan()        noexcept { return Color(Value::Cyan);    };
        static constexpr Color White()       noexcept { return Color(Value::White);   };
        static constexpr Color BrightBlack()   noexcept { return Color(Value::BrightBlack);   };
        static constexpr Color BrightRed()     noexcept { return Color(Value::BrightRed);     };
        static constexpr Color BrightGreen()   noexcept { return Color(Value::BrightGreen);   };
        static constexpr Color BrightYellow()  noexcept { return Color(Value::BrightYellow);  };
        static constexpr Color BrightBlue()    noexcept { return Color(Value::BrightBlue);    };
        static constexpr Color BrightMagenta() noexcept { return Color(Value::BrightMagenta); };
        static constexpr Color BrightCyan()    noexcept { return Color(Value::BrightCyan);    };
        static constexpr Color BrightWhite()   noexcept { return Color(Value::BrightWhite);   };

    };


    export bool is_tty(FILE* f = stdout) noexcept {
        // this lambda runs exactly once, at first call
        static const bool cached = [f]() {
    #ifdef _WIN32
            return _isatty(_fileno(f)) != 0;
    #else
            return ::isatty(::fileno(f)) != 0;
    #endif
        }();

        return cached;
    }

}
