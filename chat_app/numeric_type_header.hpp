#ifndef CHAT_APP_NUMERIC_TYPE_HEADER_HPP
#define CHAT_APP_NUMERIC_TYPE_HEADER_HPP

#include <cstdint>
#include <array>

template <typename T>
class numeric_type_header
{
private:
    static constexpr auto bits_in_byte = 8;

public:
    using numeric_type = T;

    static constexpr auto length = sizeof(numeric_type);

    static numeric_type decode_header(const std::array<std::uint8_t, length>& header)
    {
        numeric_type body_length = 0;

        for (const auto byte : header) {
            body_length <<= bits_in_byte;
            body_length |= byte;
        }

        return body_length;
    }

    static std::array<std::uint8_t, length> encode_header(numeric_type body_length)
    {
        std::array<std::uint8_t, length> header;
        int i = length - 1;

        for (auto& byte : header) {
            byte = static_cast<std::uint8_t>(body_length) / (static_cast<std::size_t>(1) << (bits_in_byte * i));
            --i;
        }

        return header;
    }
}; // class numeric_type_header

#endif // CHAT_APP_NUMERIC_TYPE_HEADER_HPP
