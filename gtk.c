/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthouard <pthouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 04:37:53 by pthouard          #+#    #+#             */
/*   Updated: 2017/10/18 04:39:10 by pthouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	quitter(GtkWidget *widget)
{
	gtk_widget_destroy(widget);
	gtk_main_quit();
}

void	creer_file_selection(GtkWindow *win)
{
	GtkWidget			*dialog;
	GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
	gint				res;

	dialog = gtk_file_chooser_dialog_new ("Open File",
			win,
			action,
			"_Cancel",
			GTK_RESPONSE_CANCEL,
			"_Open",
			GTK_RESPONSE_ACCEPT,
			NULL);

	res = gtk_dialog_run (GTK_DIALOG (dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
		char* gfilename = gtk_file_chooser_get_filename (chooser);
		g_free (gfilename);
		filename = ft_strdup(gfilename);
		printf("filename = %s\n", filename);
	gtk_widget_destroy((GtkWidget *)win);
	gtk_main_quit();
	}

	gtk_widget_destroy (dialog);
}
