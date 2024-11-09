#include <gtk/gtk.h>
#include <stdlib.h>

// Функція для виконання команди перезавантаження
static void on_shutdown_button_clicked(GtkWidget *widget, gpointer data) {
    system("shutdown -r");  // Перезавантаження системи
}

// Функція для створення вікна
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;

    // Створення основного вікна
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Перезавантаження");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // Створення кнопки
    button = gtk_button_new_with_label("Перезавантажити");
    g_signal_connect(button, "clicked", G_CALLBACK(on_shutdown_button_clicked), NULL);

    // Додавання кнопки до вікна
    gtk_container_add(GTK_CONTAINER(window), button);

    // Показати вікно та всі елементи
    gtk_widget_show_all(window);
}

// Основна функція
int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    // Ініціалізація GTK додатку
    app = gtk_application_new("com.example.shutdown", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Запуск додатку
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
