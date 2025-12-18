#include "register_types.h"

#include "gdexample.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

/* What is ModuleInitializationLevel??? */
void init_example_module(ModuleInitializationLevel p_level) { 
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {return;}

    GDREGISTER_RUNTIME_CLASS(GDExample);
}

void uninit_example_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {return;}
}

extern "C" {
    GDExtensionBool GDE_EXPORT example_lib_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_lib, GDExtensionInitialization *r_init) {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_lib, r_init);

        init_obj.register_initializer(init_example_module);
        init_obj.register_terminator(uninit_example_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}