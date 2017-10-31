/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthouard <pthouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 02:24:01 by pthouard          #+#    #+#             */
/*   Updated: 2017/10/31 03:23:29 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				quitter(GtkWidget *widget)
{
	gtk_widget_destroy(widget);
	gtk_main_quit();
}

static GtkWidget	*creer_file_selection_bis(void)
{
	GtkWidget				*dialog;
	GtkWidget				*parent;
	GtkFileChooserAction	action;

	action = GTK_FILE_CHOOSER_ACTION_OPEN;
	parent = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	dialog = gtk_file_chooser_dialog_new("Open File",
	(GtkWindow *)parent, action, "_Cancel", GTK_RESPONSE_CANCEL, "_Open",
	GTK_RESPONSE_ACCEPT, NULL);
	return (dialog);
}

void				creer_file_selection(void)
{
	GtkWidget				*dialog;
	gint					res;
	GtkFileChooser			*chooser;
	char					*gfilename;

	dialog = creer_file_selection_bis();
	gtk_window_set_position((GtkWindow *)dialog, GTK_WIN_POS_CENTER);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		chooser = GTK_FILE_CHOOSER(dialog);
		gfilename = gtk_file_chooser_get_filename(chooser);
		g_free(gfilename);
		g_filename = ft_strdup(gfilename);
	}
	gtk_widget_destroy(dialog);
}

void				activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget	*window;
	GtkWidget	*button;
	GtkWidget	*button_box;

	(void)user_data;
	window = gtk_application_window_new(app);
	gtk_window_set_position((GtkWindow *)window, GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "Window");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
	button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add(GTK_CONTAINER(window), button_box);
	button = gtk_button_new_with_mnemonic("_Explorer ...");
	g_signal_connect(button, "clicked", G_CALLBACK(creer_file_selection), NULL);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy),
	window);
	gtk_container_add(GTK_CONTAINER(button_box), button);
	gtk_widget_show_all(window);
}
