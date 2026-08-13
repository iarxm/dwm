# dwm bindings

## Launchers and system controls

| Keys                               | Action                                         |
| ---------------------------------- | ---------------------------------------------- |
| `Alt+Super+Return`                 | Open plain `st`                                |
| `Alt+Return`                       | Open `st tmux`                                 |
| `Alt+n`                            | Open `nnn` in `st`                             |
| `Super+n`                          | Open `nnn` in alternate `st` profile           |
| `Alt+Super+m`                      | Open `neomutt` in `st`                         |
| `Alt+a`                            | Open `qb w.gpt`                                |
| `Super+b`                          | Open Microsoft Edge                            |
| `Alt+Super+b`                      | Open `qb`                                      |

## Menus, controls and launchers

| Keys                               | Action                                         |
| ---------------------------------- | ---------------------------------------------- |
| `Ctrl+p`                           | Open `dmenu_run`                               |
| `Super+p`                          | Open `passmenu`                                |
| `Alt+p`                            | Open `dmux`                                    |
| `Ctrl+Super+p`                     | Open Bluetooth menu                            |
| `Alt+Super+p`                      | Open NetworkManager dmenu                      |
| `Alt+b`                            | Toggle status bar                              |
| `Alt+s`                            | Screenshot with `maimx screen`                 |
| `Super+s`                          | Screenshot with `maimx flameshot`              |
| `Alt+Ctrl+k`                       | Increase default-sink volume by 5%             |
| `Alt+Ctrl+j`                       | Decrease default-sink volume by 5%             |
| `Alt+Ctrl+m`                       | Toggle default-sink mute                       |
| `Alt+Ctrl+l`                       | Toggle MPD playback                            |
| `Alt+Super+s`                      | Suspend the system                             |
| `Alt+Shift+q`                      | Quit dwm                                       |

## Window and layout management

| Keys                               | Action                                         |
| ---------------------------------- | ---------------------------------------------- |
| `Alt+q`                            | Close focused window                           |
| `Alt+t`                            | Tiled layout (`[]=`)                           |
| `Alt+f`                            | Floating layout (`><>`)                        |
| `Alt+m`                            | Monocle layout (`[M]`)                         |
| `Alt+Shift+Space`                  | Cycle layouts                                  |
| `Alt+Space` or `Super+Space`       | View previous tag set                          |
| `Alt+j` / `Alt+k`                  | Focus next / previous window                   |
| `Alt+i` / `Alt+d`                  | Increase / decrease master-window count        |
| `Alt+h` / `Alt+l`                  | Shrink / grow master area by 5%                |
| `Alt+Super+k`                      | Promote focused window to master               |
| `Alt+Ctrl+Space`                   | Toggle focused window floating                 |
| `Alt+,` / `Alt+.`                  | Focus previous / next monitor                  |
| `Alt+Shift+,` / `Alt+Shift+.`      | Send focused window to previous / next monitor |

## Tags

| Keys                               | Action                                         |
| ---------------------------------- | ---------------------------------------------- |
| `Alt+1` through `Alt+9`            | View tag 1 through 9                           |
| `Alt+o`                            | View tag `xoo`                                 |
| `Super+m`                          | View tag `xml`                                 |
| `Super+a`                          | View tag `xau`                                 |
| `Super+r`                          | View tag `xrd`                                 |
| `Super+o`                          | View tag `xmj`                                 |
| `Alt+0`                            | View all tags                                  |
| `Alt+Shift+0`                      | Tag focused window with all tags               |

For every individual tag shortcut above:

| Modifier added to the tag shortcut | Action                                         |
| ---------------------------------- | ---------------------------------------------- |
| `Ctrl`                             | Toggle that tag in the current view            |
| `Shift`                            | Move focused window to that tag                |
| `Ctrl+Shift`                       | Toggle that tag on the focused window          |

## Mouse bindings

| Where         | Input                 | Action                                         |
| ------------- | --------------------- | ---------------------------------------------- |
| Layout symbol | Left click            | Cycle layouts                                  |
| Layout symbol | Right click           | Monocle layout                                 |
| Window title  | Middle click          | Promote window to master                       |
| Status text   | Middle click          | Open `st tmux`                                 |
| Client window | `Alt` + left drag     | Move window                                    |
| Client window | `Alt` + middle click  | Toggle floating                                |
| Client window | `Alt` + right drag    | Resize window                                  |
| Tag bar       | Left click            | View clicked tag                               |
| Tag bar       | Right click           | Toggle clicked tag in view                     |
| Tag bar       | `Alt` + left click    | Tag focused window with clicked tag            |
| Tag bar       | `Alt` + right click   | Toggle clicked tag on focused window           |
