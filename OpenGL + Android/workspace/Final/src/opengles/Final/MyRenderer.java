package opengles.Final;

//	import
	import javax.microedition.khronos.egl.EGLConfig;
	import javax.microedition.khronos.opengles.GL10;
	import android.app.Activity;
	import android.content.Context;
	import android.widget.Button;
	import android.opengl.GLSurfaceView;
	import android.view.View.OnClickListener;
	import android.view.View;
	import android.opengl.GLU;

public class MyRenderer extends Activity implements GLSurfaceView.Renderer {

	private Shape myShape;
	private Shape2 myShape2;
	private Shape3 myShape3;
	private Shape2 myShape4;

	View view;

	Button buttonXn;
	Button buttonXr;
	Button buttonXp;
	Button buttonYn;
	Button buttonYr;
	Button buttonYp;
	Button buttonZn;
	Button buttonZp;
	Button buttonZr;

	private View parent;

	private static float angleCubeX = 0;
	private static float angleCubeY = 0;
	private static float angleCubeZ = 0;
	private static float speedCubeX = 0.0f;
	private static float speedCubeY = 0.0f;
	private static float speedCubeZ = 0.0f;

	public MyRenderer( Context context , View parent ) {
		myShape = new Shape();
		myShape2 = new Shape2();
		myShape3 = new Shape3();
		myShape4 = new Shape2();
		this.parent = parent;
		addListenerOnButton();
		}

	public void addListenerOnButton(){
		buttonXn = ( Button ) parent.findViewById( R.id.buttonXn );
		buttonXr = ( Button ) parent.findViewById( R.id.buttonXr );
		buttonXp = ( Button ) parent.findViewById( R.id.buttonXp );
		buttonYn = ( Button ) parent.findViewById( R.id.buttonYn );
		buttonYr = ( Button ) parent.findViewById( R.id.buttonYr );
		buttonYp = ( Button ) parent.findViewById( R.id.buttonYp );
		buttonZn = ( Button ) parent.findViewById( R.id.buttonZn );
		buttonZr = ( Button ) parent.findViewById( R.id.buttonZr );
		buttonZp = ( Button ) parent.findViewById( R.id.buttonZp );

		buttonXn.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeX = speedCubeX - 1.0f;
				}
			} );
		buttonXr.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeX = 0.0f;
				}
			} );
		buttonXp.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeX = speedCubeX + 1.0f;
				}
			} );
		buttonYn.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeY = speedCubeY - 1.0f;
				}
			} );
		buttonYr.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeY = 0.0f;
				}
			} );
		buttonYp.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeY = speedCubeY + 1.0f;
				}
			} );
		buttonZn.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeZ = speedCubeZ - 1.0f;
				}
			} );
		buttonZr.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeZ = 0.0f;
				}
			} );
		buttonZp.setOnClickListener( new OnClickListener(){
			@Override public void onClick( View view ){
				speedCubeZ = speedCubeZ + 1.0f;
				}
			} );
		}

	@Override public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		gl.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		gl.glClearDepthf(1.0f);
		gl.glEnable(GL10.GL_DEPTH_TEST);
		gl.glDepthFunc(GL10.GL_LEQUAL);
		gl.glHint(GL10.GL_PERSPECTIVE_CORRECTION_HINT, GL10.GL_NICEST);
		gl.glShadeModel(GL10.GL_SMOOTH);
		gl.glDisable(GL10.GL_DITHER);
		}

	@Override public void onSurfaceChanged(GL10 gl, int width, int height) {
		if (height == 0) height = 1;
		float aspect = (float)width / height;
		gl.glViewport(0, 0, width, height);
		gl.glMatrixMode(GL10.GL_PROJECTION);
		gl.glLoadIdentity();
		GLU.gluPerspective(gl, 45, aspect, 0.1f, 100.f);
		gl.glMatrixMode(GL10.GL_MODELVIEW);
		gl.glLoadIdentity();
		}

	@Override public void onDrawFrame(GL10 gl) {
		gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);
		gl.glLoadIdentity();
		gl.glTranslatef( -1.5f , 0.0f , -12.0f );
		gl.glRotatef( angleCubeX , 1.0f , 0.0f , 0.0f );
		gl.glRotatef( angleCubeY , 0.0f , 1.0f , 0.0f );
		gl.glRotatef( angleCubeZ , 0.0f , 0.0f , 1.0f );
		myShape2.draw( gl );
		gl.glLoadIdentity();
		gl.glTranslatef( 1.5f , 0.0f , -12.0f );
		gl.glRotatef( angleCubeX , 1.0f , 0.0f , 0.0f );
		gl.glRotatef( angleCubeY , 0.0f , 1.0f , 0.0f );
		gl.glRotatef( angleCubeZ , 0.0f , 0.0f , 1.0f );
		myShape.draw( gl );
		gl.glLoadIdentity();
		gl.glTranslatef( 0.0f , 3.0f , -12.0f );
		gl.glRotatef( angleCubeX , 1.0f , 0.0f , 0.0f );
		gl.glRotatef( angleCubeY , 0.0f , 1.0f , 0.0f );
		gl.glRotatef( angleCubeZ , 0.0f , 0.0f , 1.0f );
		myShape3.draw( gl );
		gl.glLoadIdentity();
		gl.glTranslatef( 0.0f , -5.0f , -24.0f );
		gl.glRotatef( angleCubeX + 180.0f , 1.0f , 0.0f , 0.0f );
		gl.glRotatef( angleCubeY , 0.0f , 1.0f , 0.0f );
		gl.glRotatef( angleCubeZ , 0.0f , 0.0f , 1.0f );
		myShape4.draw( gl );
		angleCubeX += speedCubeX;
		angleCubeY += speedCubeY;
		angleCubeZ += speedCubeZ;
		}
	}