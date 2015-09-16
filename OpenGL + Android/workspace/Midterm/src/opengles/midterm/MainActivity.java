package opengles.midterm;

import android.app.Activity;
import android.support.v7.app.ActionBar;
import android.support.v7.app.ActionBarActivity;
import android.support.v4.app.Fragment;
import android.view.Menu;
import android.view.View;
import android.view.ViewGroup;
import android.content.Context;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.os.Build;
import android.view.LayoutInflater;
import android.view.MenuItem;

public class MainActivity extends Activity {

  private GLSurfaceView glView;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    // Create a GLSurfaceView instance and set it
    // as the ContentView for this Activity.
    glView = new MyGLSurfaceView(this);
    setContentView(glView);
  }


  @Override
  public boolean onCreateOptionsMenu(Menu menu) {
	  
	  getMenuInflater().inflate(R.menu.main, menu);
	  return true;
  }
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		  int id = item.getItemId();
		  if (id == R.id.action_settings) {
			  return true;
		  }
		  return super.onOptionsItemSelected(item);
	}
}

class MyGLSurfaceView extends GLSurfaceView {

  public MyGLSurfaceView(Context context){
    super(context);
    // Create an OpenGL ES 2.0 context
    setEGLContextClientVersion ( 2 );
    // Render the view only when there is a change in the drawing data
    // Set the Renderer for drawing on the GLSurfaceView
    setRenderer(new MyRenderer());
  }
}
	