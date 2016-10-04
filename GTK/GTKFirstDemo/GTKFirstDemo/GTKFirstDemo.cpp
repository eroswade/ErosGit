// GTKFirstDemo.cpp : 定义控制台应用程序的入口点。
//

//#include <stdio.h>

#include <gtk/gtk.h>

typedef struct _Ourarg Ourarg;
struct _Ourarg {
	GtkWidget *fixed;
	GtkWidget *image;
	gint right;
	gint left;
};
void	image_go(Ourarg *arg)
{
	gint x, y, toward;
	x = y = arg->left;
	toward = 1;
	for(;;)
	{
		g_usleep(1500000);// 1.5秒sleep 这是微秒级的SLEEP
		gdk_threads_enter();
		gtk_fixed_move(GTK_FIXED(arg->fixed),arg->image, x, y);
		switch(toward)
		{
		case 1:
			x = x + 10;
			if( x > arg->right ) toward = 2;
			break;
		case 2:
			y = y + 10;
			if( y > arg->right ) toward = 3;
			break;
		case 3:
			x = x - 10;
			if( x < arg->left ) toward = 4;
			break;
		case 4:
			y = y -10;
			if( y < arg->left ) toward = 1;
		}
		gdk_threads_leave();
	}
}


void store_filename (GtkWidget *widget, gpointer user_data) {
	GtkWidget *file_selector = GTK_WIDGET (user_data);
	const gchar *selected_filename;
	selected_filename = gtk_file_selection_get_filename (GTK_FILE_SELECTION (file_selector));
	g_print ("Selected filename: %s\n", selected_filename);
}

void create_file_selection (void) {
	GtkWidget *file_selector;
	/* Create the selector */
	file_selector = gtk_file_selection_new ("Please select a file for editing.");
	g_signal_connect (GTK_FILE_SELECTION (file_selector)->ok_button,
		"clicked",
		G_CALLBACK (store_filename),
		file_selector);
	/* Ensure that the dialog box is destroyed when the user clicks a button. */
	g_signal_connect_swapped (GTK_FILE_SELECTION (file_selector)->ok_button,
		"clicked",
		G_CALLBACK (gtk_widget_destroy),
		file_selector);
	g_signal_connect_swapped (GTK_FILE_SELECTION (file_selector)->cancel_button,
		"clicked",
		G_CALLBACK (gtk_widget_destroy),
		file_selector);
	/* Display that dialog */
	gtk_widget_show (file_selector);
}

int	main(int argc, char* argv[])
{
	//setlocale( LC_ALL, "zh_CN.GB2312" ); 
	GtkWidget *window;
	GtkWidget *vbox, *viewport, *button;
	GtkWidget *image, *fixed;
	Ourarg *arg;

	// 判断是否支持线程
	if(!g_thread_supported()) g_thread_init(NULL);
	// 初始化线程
	gdk_threads_init();
	//初始化GTK
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),g_locale_to_utf8("线程测试",-1,NULL,NULL,NULL));

	// 连接关闭按钮
	g_signal_connect(G_OBJECT(window),"delete_event",
		G_CALLBACK(gtk_main_quit),NULL);
	// 设置窗口属性
	gtk_container_set_border_width(GTK_CONTAINER(window),2);
	//增加CONTAINER
	vbox = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window),vbox);

	// 创建一个FIX对象
	fixed = gtk_fixed_new();
	gtk_widget_set_usize(fixed,340,340);//设置大小 
	viewport = gtk_viewport_new(NULL,NULL);
	//创建VIEWPORT用来支持FIX对象
	gtk_box_pack_start(GTK_BOX(vbox),viewport,FALSE,FALSE,5);
	gtk_container_add(GTK_CONTAINER(viewport),fixed);
	g_print("test");
	//把图LOAD到FIX
	image = gtk_image_new_from_file("ss.png");
	gtk_fixed_put(GTK_FIXED(fixed),image,40,40);

	// 创建BUTTON
	button = gtk_button_new_with_label(g_locale_to_utf8("退出",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(vbox),button,FALSE,FALSE,5);
	g_signal_connect(G_OBJECT(button),"clicked",
		G_CALLBACK(create_file_selection),NULL);//gtk_main_quit

	// 配置文件方法
	gsize length = 0;
	GKeyFile* config = g_key_file_new(); 
	g_key_file_set_value(config,"STARTUP","x","300");
	g_key_file_set_string(config,"STARTUP","y","600");
	g_key_file_set_boolean(config,"STARTUP","center",TRUE);
	gchar* content = g_key_file_to_data(config,&length,NULL);
	g_print("%s\n",content);

	FILE* fp = fopen("./019.ini","w");
	if(fp == NULL) return -1;
	fwrite(content,1,length,fp);
	fclose(fp);
	g_key_file_free(config);


	gtk_widget_show_all(window);


	arg = g_new(Ourarg,1);
	arg->fixed = fixed;
	arg->image = image;
	arg->left = 40;
	arg->right = 260;
	g_thread_create((GThreadFunc)image_go, arg, FALSE,NULL);

	gdk_threads_enter();
	gtk_main();
	gdk_threads_leave();
	return FALSE;
}