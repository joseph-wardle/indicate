module;

#include <chrono>
#include <iostream>
#include <thread>
#include <stop_token>
#include <array>
#include <string_view>


export module indicate.spinner;

import indicate.util;

namespace indicate {

    export class Spinner {
    public:
        using ms = std::chrono::milliseconds;

        // Default braille frames as a compile-time array
        static constexpr std::array<std::string_view,10> default_frames = {
            "⠋","⠙","⠹","⠸","⠼","⠴","⠦","⠧","⠇","⠏"
        };

        explicit Spinner(
            const std::string_view message    = {},
            const ms               interval   = ms{100},
                  std::ostream&    os         = std::cout,
            const std::array<std::string_view,10> &frames = default_frames
        )
        : message_(message)
        , interval_(interval)
        , os_(os)
        , frames_(frames)
        , worker_([this](const std::stop_token &st){
            while(!st.stop_requested()){
                tick();
                std::this_thread::sleep_for(interval_);
            }
          })
        {}

        ~Spinner() {
            clear_line();
        }

        Spinner& set_message(const std::string_view msg) noexcept {
            message_ = msg;
            return *this;
        }

        void tick() noexcept {
            if (!is_tty()) return;
            // atomic fetch_add for lock-free wraparound
            const size_t i = index_.fetch_add(1, std::memory_order_relaxed) % frames_.size();
            os_ << "\r" << frames_[i] << ' ' << message_ << std::flush;
        }

        void clear_line() const noexcept {
            // ANSI “erase line” + carriage return
            os_ << "\r\033[2K" << std::flush;
        }

    private:
        std::string                      message_;
        ms                               interval_;
        std::ostream&                    os_;
        std::array<std::string_view,10>  frames_;
        std::atomic<size_t>              index_{0};
        std::jthread                     worker_;
    };

} // namespace indicate
