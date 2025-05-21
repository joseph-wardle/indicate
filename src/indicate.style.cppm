module;

#include <string>

export module indicate.style;

import indicate.util;

constexpr inline std::string_view reset_all = "\x1b[0m";

namespace indicate {
    export class Style {
    private:
        Color fg_ = Color::Default();
        Color bg_ = Color::Default();
    public:
        Style() = default;

        Style& foreground(const Color c)   { fg_ = c; return *this; }
        Style& background(const Color c)   { bg_ = c; return *this; }

        [[nodiscard]] std::string apply(std::string_view const& text) const noexcept {
            auto const fg_code = fg_.to_ansi_fg();
            auto const bg_code = bg_.to_ansi_bg();

            std::string out;
            out.reserve(fg_code.size() + bg_code.size() + text.size() + reset_all.size());
            out += fg_code;
            out += bg_code;
            out += text;
            out += reset_all;
            return out;
        }


        [[nodiscard]] std::string operator()(std::string_view const& text) const {
            return apply(text);
        }

        void write(std::ostream& os, std::string_view const& text) const {
            auto const fg_code = fg_.to_ansi_fg();
            auto const bg_code = bg_.to_ansi_bg();
            os << fg_code << bg_code << text << reset_all;
        }

    };
}
