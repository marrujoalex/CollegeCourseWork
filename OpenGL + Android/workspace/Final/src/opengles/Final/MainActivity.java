package opengles.Final;


//	import
	import android.support.v7.app.ActionBarActivity;
	import android.os.Bundle;
	import android.view.Menu;
	import android.view.MenuItem;
	import android.view.View;

public class MainActivity extends ActionBarActivity {

	MyGLSurfaceView mGLView;
	MyRenderer myRenderer;

	@Override protected void onCreate( Bundle savedInstanceState ){
		super.onCreate( savedInstanceState );
		setContentView( R.layout.activity_main );
		View parent = findViewById( R.id.container );
		myRenderer = new MyRenderer( this , parent );
		mGLView = ( MyGLSurfaceView ) findViewById( R.id.surfaceviewclass );
		mGLView.setRenderer( myRenderer );
		}

	@Override public boolean onCreateOptionsMenu( Menu menu ){
		getMenuInflater().inflate( R.menu.main , menu);
		return true;
		}

	@Override public boolean onOptionsItemSelected( MenuItem item ){
		int id = item.getItemId();
		if( id == R.id.action_settings ){
			return true;
			}
		return super.onOptionsItemSelected( item );
		}
	}