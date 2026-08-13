# Maintaining the dwm binding cheat sheet

`config.h` is the authoritative source for the bindings shown in
`../bindings.md`. Update the cheat sheet in the same change as every binding,
tag, layout, command, or mouse-binding change.

## Workflow

1. Read the complete `Key keys[]` and `Button buttons[]` tables in `config.h`,
   along with the `tags[]`, `layouts[]`, and command arrays used by `spawn`.
2. Translate modifiers consistently: `MODKEY` is `Alt` (`Mod1`) and `MODKY1`
   is `Super` (`Mod4`). Preserve `ControlMask` as `Ctrl` and `ShiftMask` as
   `Shift`.
3. Expand `TAGKEYS`: each tag key has view, toggle-view, tag-window, and
   toggle-window-tag variants. The compact explanation in `bindings.md` is
   intentional; keep it correct if the macro changes.
4. Keep every Markdown table source-aligned: pad cells and separator rows so
   their column borders line up. This improves both reviewability and terminal
   viewing in `less`.
5. Do not add a dwm key binding merely to launch `dwm-cheat`. It is an
   installed command for deliberate use, and binding selection is user-owned.

## Verify

Run the following from the repository root after editing:

```sh
make
make DESTDIR="$(mktemp -d)" install
git diff --check
```

The staged installation must contain an executable
`usr/local/bin/dwm-cheat` and the document at
`usr/local/share/doc/dwm/bindings.md` with the default `PREFIX`. Test a
checkout copy without installing it by overriding its document path:

```sh
DWM_CHEAT_FILE=bindings.md ./dwm-cheat
```

Use `make PREFIX=/usr install` only when the intended system-wide location is
`/usr/bin/dwm-cheat` and `/usr/share/doc/dwm/bindings.md`.
