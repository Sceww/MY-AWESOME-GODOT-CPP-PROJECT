#pragma once

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {
    class GDExample : public Sprite2D {
        GDCLASS(GDExample, Sprite2D)
        
        private:
            double time_passed;
            double amplitude;
            double speed;
        protected:
            static void _bind_methods(); /* Static function used by Godot to find which methods are callable and which properties are exposed */
        public:
            GDExample(); /* Constructor */
            ~GDExample(); /* Destructor */
            
            void _process(double delta) override; /* Works exactly how _process() -> void works in GDScript */

            void set_amplitude(const double p_amplitude);
            double get_amplitude() const;

            void set_speed(const double p_speed);
            double get_speed() const;
    };
}