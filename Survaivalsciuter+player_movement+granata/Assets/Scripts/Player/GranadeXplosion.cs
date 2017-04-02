using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GranadeXplosion : MonoBehaviour 
{
	public float WaitToXplode=2.0f;
	public int Damage = 500;
	public float DamageArea = 8.0f;
	public float LaunchSpeed = 700;
	public Rigidbody _rb;

	RaycastHit shootHit;

	void Awake()
	{
		_rb.AddForce (transform.forward * LaunchSpeed);
	}

	void Update () 
	{
		WaitToXplode-=Time.deltaTime;
		if (WaitToXplode <= 0.0f) 
		{
			xplode ();
		}
	}

	void FixedUpdate()
	{
		
	}

	private void xplode ()
	{
		Collider[] inRange = Physics.OverlapSphere (transform.position, DamageArea);
		foreach (Collider col in inRange) 
		{
			EnemyHealth enemyHealth = col.GetComponent<EnemyHealth> ();
			if(enemyHealth != null)
			{
				enemyHealth.TakeGranadeDamage(Damage);
			}
		}

		Destroy (gameObject);
	}
}
