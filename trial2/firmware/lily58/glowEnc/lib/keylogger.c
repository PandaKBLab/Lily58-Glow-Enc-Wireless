#include <stdio.h>
#include "action.h"
#include "lily58.h"

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[60] = {
  ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
  'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ',
  ' ', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

const char code_to_name_2[17] = {
  '/', '*', '-', '+', ' ', '1', '2', 
  '3', '4', '5', '6', '7', '8', '9', '0', '.'
};

void set_keylog(uint16_t keycode, keyrecord_t *record)
{
  char name = ' ';
  if (keycode < 60)
  {
    name = code_to_name[keycode];
  } else if (keycode >= 84 && keycode <= 99 ) {
    name = code_to_name_2[keycode - 84];
  }
  switch (keycode)
  {
  case KC_LCTRL:
    name = 'C';
    break;
  case KC_LSFT:
    name = 'S';
    break;
  case KC_TAB:
    name = 'T';
    break;
  case KC_ESC:
    name = 'E';
    break;
  case KC_LGUI:
    name = 'G';
    break;
  case KC_LALT:
    name = 'A';
    break;
  case KC_SPC:
    name = ' ';
    break;
  case KC_ENT:
    name = 'E';
    break;
  case KC_DELETE:
    name = 'D';
    break;
  case KC_PGUP:
    name = 'P';
    break;
  case KC_PGDN:
    name = 'p';
    break;
  case KC_LEFT:
    name = '<';
    break;
  case KC_UP:
    name = '^';
    break;
  case KC_DOWN:
    name = 'v';
    break;
  case KC_RGHT:
    name = '>';
    break;
  default:
    break;
  }
  if (keycode == KC_LCTRL)
  {
    name = 'C';
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1)
  {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++)
    {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void)
{
  return keylog_str;
}

const char *read_keylogs(void)
{
  return keylogs_str;
}
