add_library(Classes
        "src/Background.cpp"
        "src/Player.cpp"
        "src/Input.cpp"
        "src/Collision2D.cpp"
        "src/Fire.cpp"
        "src/Rock.cpp"
        "src/Score.cpp"
)
target_include_directories(Classes PUBLIC "include")
target_link_libraries(Classes PUBLIC SDL3::SDL3)
target_link_libraries(Classes PUBLIC SDL3_image::SDL3_image)
target_link_libraries(Classes PUBLIC SDL3_ttf::SDL3_ttf)