// 0 ~ 111, ignore rest key
// 0x1d0: key_fn

static char *scancode_to_ascii[] = { 
    "[Reserved]", "[Esc]",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", 
    "-", "=", "[Backspace]", "[Tab]", 
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", 
    "[", "]", "[Enter]", "[LCtrl]",
    "a", "s", "d", "f", "g", "h", "j", "k", "l",
    ";", "'", "`", "[LShift]", "\\",
    "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", 
    "[RShift]", "[NL*]", "[LAlt]", "[Space]", "[CapsLock]",
    "[F1]", "[F2]", "[F3]", "[F4]", "[F5]",
    "[F6]", "[F7]", "[F8]", "[F9]", "[F1O]",
    "[NumLock]", "[ScrollLock]",
    "[NL7]", "[NL8]", "[NL9]", "[NL-]",
    "[NL4]", "[NL5]", "[NL6]", "[NL+]",
    "[NL1]", "[NL2]", "[NL3]", "[NL0]", "[NL.]",
    "[Unknown]", "[ZENKAKUHANKAKU]", "[102ND]", "[F11]", "[F12]",
    "[RO]", "[KATAKANA]", "[HIRAGANA]", "[HENKAN]",
    "[KATAKANAHIRAGANA]", "[MUHENKAN]", "[KPJPCOMMA]",
    "[NLEnter]", "[RCtrl]", "[NL/]", "[SysRq]", "[RAlt]",
    "[LINEFEED]", "[Home]", "[Up]", "[PageUp]", "[Left]", "[Right]", 
    "[End]", "[Down]", "[PageDown]", "[Insert]", "[Delete]"
};

static char *caps_scancode_to_ascii[] = {
    "[Reserved]", "[Esc]",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", 
    "-", "=", "[Backspace]", "[Tab]", 
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", 
    "[", "]", "[Enter]", "[LCtrl]",
    "A", "S", "D", "F", "G", "H", "J", "K", "L",
    ";", "'", "`", "[LShift]", "\\",
    "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", 
    "[RShift]", "[NL*]", "[LAlt]", "[Space]", "[CapsLock]",
    "[F1]", "[F2]", "[F3]", "[F4]", "[F5]",
    "[F6]", "[F7]", "[F8]", "[F9]", "[F1O]",
    "[NumLock]", "[ScrollLock]",
    "[NL7]", "[NL8]", "[NL9]", "[NL-]",
    "[NL4]", "[NL5]", "[NL6]", "[NL+]",
    "[NL1]", "[NL2]", "[NL3]", "[NL0]", "[NL.]",
    "[Unknown]", "[ZENKAKUHANKAKU]", "[102ND]", "[F11]", "[F12]",
    "[RO]", "[KATAKANA]", "[HIRAGANA]", "[HENKAN]",
    "[KATAKANAHIRAGANA]", "[MUHENKAN]", "[KPJPCOMMA]",
    "[NLEnter]", "[RCtrl]", "[NL/]", "[SysRq]", "[RAlt]",
    "[LINEFEED]", "[Home]", "[Up]", "[PageUp]", "[Left]", "[Right]", 
    "[End]", "[Down]", "[PageDown]", "[Insert]", "[Delete]"
};

static char *shift_scancode_to_ascii[] = {
    "[Reserved]", "[Esc]",
    "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", 
    "_", "+", "[Backspace]", "[Tab]", 
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", 
    "{", "}", "[Enter]", "[LCtrl]",
    "A", "S", "D", "F", "G", "H", "J", "K", "L",
    ":", "\"", "~", "[LShift]", "|",
    "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", 
    "[RShift]", "[NL*]", "[LAlt]", "[Space]", "[CapsLock]",
    "[F1]", "[F2]", "[F3]", "[F4]", "[F5]",
    "[F6]", "[F7]", "[F8]", "[F9]", "[F1O]",
    "[NumLock]", "[ScrollLock]",
    "[NL7]", "[NL8]", "[NL9]", "[NL-]",
    "[NL4]", "[NL5]", "[NL6]", "[NL+]",
    "[NL1]", "[NL2]", "[NL3]", "[NL0]", "[NL.]",
    "[Unknown]", "[ZENKAKUHANKAKU]", "[102ND]", "[F11]", "[F12]",
    "[RO]", "[KATAKANA]", "[HIRAGANA]", "[HENKAN]",
    "[KATAKANAHIRAGANA]", "[MUHENKAN]", "[KPJPCOMMA]",
    "[NLEnter]", "[RCtrl]", "[NL/]", "[SysRq]", "[RAlt]",
    "[LINEFEED]", "[Home]", "[Up]", "[PageUp]", "[Left]", "[Right]", 
    "[End]", "[Down]", "[PageDown]", "[Insert]", "[Delete]"
};