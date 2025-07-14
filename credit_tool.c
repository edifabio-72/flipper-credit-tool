#include <furi.h>
#include <gui/gui.h>

int32_t credit_tool(void* p) {
    UNUSED(p);
    Gui* gui = furi_record_open("gui");

    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, [](Canvas* canvas, void* context){
        canvas_draw_str(canvas, 10, 10, "Credit Tool Ready!");
    }, NULL);

    gui_add_view_port(gui, view_port, GuiLayerFullscreen);
    furi_delay_ms(3000);
    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);

    furi_record_close("gui");
    return 0;
}
